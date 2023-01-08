<?php
    $path = './data/to_do_tasks.xml';

    header('Content-Type: text/plain');

    // Read the XML file & get sent data
    $doc = new DOMDocument();
    $doc->load($path);
    $tasks = file_get_contents('php://input');

    $tasksArray = explode(',', $tasks);

    $data = $doc->documentElement;

    // Delete all the child nodes of the element
    while ($data->hasChildNodes()) {
        $data->removeChild($data->firstChild);
    }
    
    // Loop through the tasks array and add each element as a child node
    foreach ($tasksArray as $item) {
        $task = $doc->createElement('task', $item);
        $data->appendChild($task);
    }

    // Save the modified XML file
    $doc->save($path);
?>
