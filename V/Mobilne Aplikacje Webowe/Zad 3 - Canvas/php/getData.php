<?php
    $path = './data/data_string.json';
    $file = fopen("semafor.txt","w+");
    flock($file, LOCK_EX);

    header('Content-Type: application/json');
    $data = file_get_contents($path);

    echo $data;

    flock($file, LOCK_UN);
    fclose($file);
?>