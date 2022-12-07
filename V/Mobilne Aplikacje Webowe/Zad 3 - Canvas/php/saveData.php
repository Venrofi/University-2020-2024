<?php
    $path = './data/data_string.json';
    $file = fopen("semafor.txt","w+");
    flock($file, LOCK_EX);

    header('Content-Type: application/json');
    $receivedData = json_decode(file_get_contents('php://input'), true);

    $url = (isset($_SERVER['HTTPS']) ? "https" : "http") . "://$_SERVER[HTTP_HOST]$_SERVER[REQUEST_URI]";
    $url_components = parse_url($url);
    parse_str($url_components['query'], $params);

    $id = $params['id'];
    $proper_id = preg_replace("([[:punct:]]|[[:alpha:]]| )",'',$id);
    echo $proper_id;
    
    $data_arr = json_decode(file_get_contents($path));

    $data_arr->data[$proper_id]->lines = $receivedData['lines'];
    $data_arr->data[$proper_id]->thumbnail = $receivedData['thumbnail'];
    $data_arr->data[$proper_id]->name = $receivedData['name'];

    $encoded = "{\"data\":";
    $encoded .= json_encode($data_arr->data);
    $encoded .= "}";
    
    file_put_contents($path, $encoded);
    
    flock($file, LOCK_UN);
    fclose($file);
?>