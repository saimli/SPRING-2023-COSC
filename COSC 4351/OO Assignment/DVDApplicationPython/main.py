#SAIM ALI
##SPRING 2021 C# OO ASSIGNMENT

import os
from DVDController import DVDController

if __name__ == '__main__':
    catalog = DVDController()

    # Restore catalog from file
    catalog.RestoreCatalog("Catalog.txt")

    # Add a new DVD
    catalog.AddDVD("A new Movie", "Horror", 90, 1993, 19.30)

    # Remove a DVD
    # catalog.RemoveDVD()

    # Edit DVD information
    # catalog.editInfo()

    # Display catalog sorted by year
    print("Catalog sorted by year:")
    sorted_DVDs = catalog.DisplayByYear()

    for dvd in sorted_DVDs:
        print(f"{dvd.Title} ({dvd.Year})")

    print()

    # Display DVDs by category
    print("DVDs in Drama category:")
    drama_DVDs = catalog.DisplayByCat("Drama")

    for dvd in drama_DVDs:
        print(f"{dvd.Title} ({dvd.Year})")

    # Save catalog to file
    catalog.SaveCatalog("Catalog.txt")
