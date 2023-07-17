//
//  TaskViewController.swift
//  iOS_Projekt
//
//  Created by macOS Ventura on 01/06/2023.
//

import UIKit
import CoreData

class TaskViewController: UIViewController {
    
    @IBOutlet var label: UILabel!
    @IBOutlet var descField: UITextView!
    @IBOutlet var imageView: UIImageView!
    
    var recipe: Recipe!
    var currentPosition: Int?
    
    var update: (()->Void)?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        label.text = recipe.name
        descField.text = recipe.desc
        if let img = recipe.image {
            imageView.image = UIImage(data: img)
        }
        
        navigationItem.rightBarButtonItem = UIBarButtonItem(title: "Usuń", style: .done, target: self, action: #selector(DeleteTask))
    }
    
    @objc func DeleteTask() {
        guard let appDelegate = UIApplication.shared.delegate as? AppDelegate else {
            return
        }
        appDelegate.dataManager.delete(recipe)
        
        update?()
        navigationController?.popViewController(animated: true)
    }
}
