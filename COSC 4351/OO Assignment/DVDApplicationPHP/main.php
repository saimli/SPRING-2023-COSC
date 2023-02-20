//SAIM ALI
//SPRING 2021 C# OO ASSIGNMENT

<?php
require_once 'DVD.php';
require_once 'DVDController.php';

$catalog = new DVDController();

// Restore catalog from file
$catalog = new DVDController();
$catalog->RestoreCatalog("Catalog.txt");

// Add a new DVD
$catalog->AddDVD("A new Movie", "Horror", 90, 1993, 19.30);

// Remove a DVD
// $catalog->RemoveDVD();

// Edit DVD information
// $catalog->editInfo();

// Display catalog sorted by year
echo "Catalog sorted by year:\n";
$sortedDVDs = $catalog->DisplayByYear();
foreach ($sortedDVDs as $dvd) {
    echo "{$dvd->Title} ({$dvd->Year})\n";
}

echo "\n";

// Display DVDs by category
echo "DVDs in Drama category:\n";
$dramaDVDs = $catalog->DisplayByCat("Drama");
foreach ($dramaDVDs as $dvd) {
    echo "{$dvd->Title} ({$dvd->Year})\n";
}

// Save catalog to file
$catalog->SaveCatalog("Catalog.txt");
