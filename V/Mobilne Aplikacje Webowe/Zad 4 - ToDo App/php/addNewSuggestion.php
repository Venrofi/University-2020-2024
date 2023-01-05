<?php
    $path = './data/suggestions.xml';

    header('Content-Type: text/plain');

    // Read the XML file & get sent data
    $doc = new DOMDocument();
    $doc->load($path);
    $newSuggestion = file_get_contents('php://input');
    
    $element = $doc->createElement('element', $newSuggestion);

    //Append new suggestion to the 'custom' section
    $doc->documentElement->childNodes[5]->appendChild($element);
    
    // Save the modified XML file
    $doc->save($path);
?>
