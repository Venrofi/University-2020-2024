<?php
    $path = './data/to_do_tasks.xml';

    // Load the XML file
    $xml = simplexml_load_file($path);

    // Return the XML data to the client
    header('Content-Type: text/xml');
    echo $xml->asXML();
?>