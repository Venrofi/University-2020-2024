//
//  EntryViewController.swift
//  iOS_Projekt
//
//  Created by macOS Ventura on 01/06/2023.
//

import UIKit
import CoreData

class EntryViewController: UIViewController, UITextFieldDelegate, UITextViewDelegate, UINavigationControllerDelegate, UIImagePickerControllerDelegate {
    
    @IBOutlet var field: UITextField!
    @IBOutlet var descField: UITextView!
    @IBOutlet var imageView: UIImageView!
    
    var imagePicker = UIImagePickerController()
    
    var update: (()->Void)?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        field.delegate = self
        descField.delegate = self
        
        let imageTap = UITapGestureRecognizer(target: self, action: #selector(imageTapped(tapGestureRecognizer:)))
        imageView.isUserInteractionEnabled = true
        imageView.addGestureRecognizer(imageTap)
        
        navigationItem.rightBarButtonItem = UIBarButtonItem(title: "Zapisz", style: .done, target: self, action: #selector(saveTask))
    }
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        saveTask()
        return true
    }
    
    @objc func saveTask() {
        guard let name = field.text, !name.isEmpty else {
            return
        }
        guard let desc = descField.text, !desc.isEmpty else {
            return
        }
        guard let appDelegate = UIApplication.shared.delegate as? AppDelegate else {
            return
        }
        
        let recipe = Recipe(entity: Recipe.entity(), insertInto: appDelegate.dataManager.context)
        recipe.name = name
        recipe.desc = desc
        recipe.image = imageView.image?.pngData()
        appDelegate.dataManager.saveContext()
        
        update?()
        navigationController?.popViewController(animated: true)
    }
    
    @objc func imageTapped(tapGestureRecognizer: UITapGestureRecognizer) {
        //let tappedImage = tapGestureRecognizer.view as! UIImageView
        ImagePickerManager().pickImage(self) { image in
            self.imageView.image = image
        }
    }
}
