//
//  DataManager.swift
//  iOS_Projekt
//
//  Created by admin on 16/06/2023.
//

import Foundation
import CoreData

class DataManager {
    lazy var persistentContainer: NSPersistentContainer = {
        let container = NSPersistentContainer(name: "RecipeList")
        container.loadPersistentStores(completionHandler: { (storeDescription, error) in
            if let error = error as NSError? {
                fatalError("Unresolved error \(error), \(error.userInfo)")
            }
        })
        return container
    }()
    
    public var context: NSManagedObjectContext {
        return persistentContainer.viewContext
    }
    
    public func fetch<T>(_ request: NSFetchRequest<T>) -> [T] where T : NSFetchRequestResult {
        do {
            return try persistentContainer.viewContext.fetch(request)
        } catch let error as NSError {
            print("Could not fetch: \(error), \(error.userInfo)")
            return []
        }
    }
    
    public func delete(_ object: NSManagedObject) {
        persistentContainer.viewContext.delete(object)
    }
    
    func saveContext() {
        let context = persistentContainer.viewContext
        if context.hasChanges {
            do {
                try context.save()
            } catch {
                let nserror = error as NSError
                fatalError("Unresolved error \(nserror), \(nserror.userInfo)")
            }
        }
    }
}
