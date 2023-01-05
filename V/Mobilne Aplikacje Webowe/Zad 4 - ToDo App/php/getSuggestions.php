<?php
    $path = './data/suggestions.xml';

    // Load the XML file
    $xml = simplexml_load_file($path);

    // Iterate over the elements in the XML file
    // foreach ($xml->record as $record) {
        // Do something with the data in the record element
        // Możnaby dodać czasowniki do tasków:
        // let movies = data.data.movies.map((movie) => "obejrzeć: " + movie);
        // let books = data.data.books.map((book) => "przeczytać: " + book);
        // let programmingBooks = data.data.programmingBooks.map(
        // (book) => "przeczytać: " + book
        // );
    // }

    // Return the XML data to the client
    header('Content-Type: text/xml');
    echo $xml->asXML();
?>