//SAIM ALI
//SPRING 2021 C# OO ASSIGNMENT

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        DVDController catalog = new DVDController();

        // Restore catalog from file
        catalog.RestoreCatalog("Catalog.txt");

        // Add a new DVD
      catalog.AddDVD("A new Movie", "Horror", 90, 1993, 19.30m);

        // Remove a DVD
        // catalog.RemoveDVD();

        // Edit DVD information
        // catalog.editInfo();

      
        // Display catalog sorted by year
        Console.WriteLine("Catalog sorted by year:");
        List<DVD> sortedDVDs = catalog.DisplayByYear();
              
        foreach (DVD dvd in sortedDVDs)
        {
            Console.WriteLine($"{dvd.Title} ({dvd.Year})");
        }


        Console.WriteLine();

      
        // Display DVDs by category
        Console.WriteLine("DVDs in Drama category:");
        List<DVD> dramaDVDs = catalog.DisplayByCat("Drama");
      
        foreach (DVD dvd in dramaDVDs)
        {
            Console.WriteLine($"{dvd.Title} ({dvd.Year})");
        }



      
        // Save catalog to file
        catalog.SaveCatalog("Catalog.txt");
      }
  }