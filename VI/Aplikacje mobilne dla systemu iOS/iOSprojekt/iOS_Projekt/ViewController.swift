//
//  ViewController.swift
//  iOS_Projekt
//
//  Created by macOS Ventura on 01/06/2023.
//

import UIKit
import CoreMotion
import CoreData

class ViewController: UIViewController {
    
    @IBOutlet var table_view: UITableView!

    @IBOutlet var searchTextField: UITextField!
    
    let motionManager = CMMotionManager()
    let shakeThreshold: Double = 1.5
    
    var isDarkModeEnabled: Bool = false
    
    var recipes: [Recipe] = []
    var allRecipes: [Recipe] = []
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.title = "Przepisy"
        
        searchTextField.delegate = self
        table_view.delegate = self
        table_view.dataSource = self
        
        setDarkMode(isDarkMode: UserDefaults().bool(forKey: "darkMode"))
        
        motionManager.accelerometerUpdateInterval = 0.1 // Update interval in seconds
        
        if motionManager.isAccelerometerAvailable {
            motionManager.startAccelerometerUpdates(to: .main) { (data, error) in
                if let acceleration = data?.acceleration {
                    let accelerationMagnitude = sqrt(pow(acceleration.x, 2) + pow(acceleration.y, 2) + pow(acceleration.z, 2))
                    
                    print("Shake się udał! \(accelerationMagnitude)")
                    
                    if accelerationMagnitude > self.shakeThreshold {
                        self.openRandomRecipe();
                    }
                }
            }
        }
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        guard let appDelegate = UIApplication.shared.delegate as? AppDelegate else {
            return
        }
        
        recipes = appDelegate.dataManager.fetch(Recipe.fetchRequest())
        allRecipes = recipes
        
        if let searchText = searchTextField.text, !searchText.isEmpty {
            textField(searchTextField, shouldChangeCharactersIn: NSRange(location: 0, length: searchText.count), replacementString: searchText)
        } else {
            updateView()
        }
        
        updateView()
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        if motionManager.isAccelerometerActive {
            motionManager.stopAccelerometerUpdates()
        }
    }
    
    override func motionEnded(_ motion: UIEvent.EventSubtype, with event: UIEvent?) {
        if motion == .motionShake {
            openRandomRecipe()
        }
    }
    
    func openRandomRecipe() {
        let randomIndex = Int.random(in: 0..<self.recipes.count)
        let recipe = self.recipes[randomIndex]
        print("Random recipe: \(recipe.name ?? "null")")
        viewRecipe(recipe: recipe, index: randomIndex)
    }
    
    func viewRecipe(recipe: Recipe, index: Int) {
        let vc = self.storyboard?.instantiateViewController(identifier: "task") as! TaskViewController
        vc.title = "Przepis"
        vc.recipe = recipe
        vc.currentPosition = index
        vc.update = {
            DispatchQueue.main.async {
                self.updateView()
            }
        }
        self.navigationController?.pushViewController(vc, animated: true)
    }
    
    func updateView() {
        table_view.reloadData()
    }
    
    @IBAction func didTapAdd() {
        let vc = storyboard?.instantiateViewController(identifier: "entry") as! EntryViewController
        vc.title = "Nowy przepis"
        vc.update = {
            DispatchQueue.main.async{
                self.updateView()
            }
        }
        navigationController?.pushViewController(vc, animated: true)
    }
    
    @IBAction func toggleMode(_ sender: Any) {
        setDarkMode(isDarkMode: !isDarkModeEnabled)
    }
    
    func setDarkMode(isDarkMode: Bool) {
        print("darkMode: \(isDarkMode)")
        let window = UIApplication.shared.windows[0]
        isDarkModeEnabled = isDarkMode
        window.overrideUserInterfaceStyle = isDarkMode ? .dark : .light
        UserDefaults().setValue(isDarkModeEnabled, forKey: "darkMode")
    }
}

extension ViewController: UITextFieldDelegate {
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        // Jeśli użytkownik wypełni pole tekstowe, pokaż przefiltrowane przepisy
        guard let currentText = textField.text else {
            return true
        }
        
        let updatedText = (currentText as NSString).replacingCharacters(in: range, with: string)
        
        if updatedText.isEmpty {
            recipes = allRecipes
        } else {
            recipes = allRecipes.filter { $0.name?.localizedCaseInsensitiveContains(updatedText) ?? false }
        }
        updateView()
        
        return true
    }
    
    func textFieldShouldClear(_ textField: UITextField) -> Bool {
        // Jeśli użytkownik wyczyści pole tekstowe, pokaż wszystkie przepisy
        recipes = allRecipes
        updateView()
        
        return true
    }

}


extension ViewController: UITableViewDelegate {
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        table_view.deselectRow(at: indexPath, animated: true)
        viewRecipe(recipe: recipes[indexPath.row], index: indexPath.row)
    }
}

extension ViewController: UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return recipes.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = table_view.dequeueReusableCell(withIdentifier: "cell", for: indexPath)
        cell.textLabel?.text = recipes[indexPath.row].name
        cell.accessoryType = .disclosureIndicator
        return cell
    }
}
