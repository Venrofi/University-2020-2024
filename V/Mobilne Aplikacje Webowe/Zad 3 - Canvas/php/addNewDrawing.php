<?php
    $path = './data/data_string.json';
    $file = fopen("semafor.txt","w+");
    flock($file, LOCK_EX);

    header('Content-Type: application/json');
    $receivedData = json_decode(file_get_contents('php://input'), true);
    $data_arr = json_decode(file_get_contents($path));

    $newDrawing = new stdClass();

    $newDrawing->name = $receivedData['name'];
    $newDrawing->lines = $receivedData['lines'];
    $newDrawing->thumbnail = $receivedData['thumbnail'];

    array_push($data_arr->data, $newDrawing);

    $encoded = "{\"data\":";
    $encoded .= json_encode($data_arr->data);
    $encoded .= "}";

    print_r($encoded);
    
    file_put_contents($path, $encoded);
    
    flock($file, LOCK_UN);
    fclose($file);
?>