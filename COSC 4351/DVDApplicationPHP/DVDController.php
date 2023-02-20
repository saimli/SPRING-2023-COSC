<?php

require_once 'DVD.php';

class DVDController
{
    private $DVDs;

    public function __construct()
    {
        $this->DVDs = array();
    }

    public function RestoreCatalog($filePath)
    {
        $lines = file($filePath, FILE_IGNORE_NEW_LINES);
        foreach ($lines as $line)
        {
            $fields = array_map('trim', explode(',', $line));

            $title = $fields[0];
            $category = $fields[1];
            $runningTime = (int) str_replace(" Mins.", "", $fields[2]);
            $year = (int) $fields[3];
            $price = (float) $fields[4];
            $this->DVDs[] = new DVD($title, $category, $runningTime, $year, $price);
        }
    }

    public function SaveCatalog($filePath)
    {
        $handle = fopen($filePath, 'w');
        foreach ($this->DVDs as $dvd)
        {
            $line = "{$dvd->Title}, {$dvd->Category}, {$dvd->RunningTime} Mins., {$dvd->Year}, {$dvd->Price}\n";
            fwrite($handle, $line);
        }
        fclose($handle);
    }

    public function AddDVD($title, $category, $runningTime, $year, $price)
    {
        $this->DVDs[] = new DVD($title, $category, $runningTime, $year, $price);
    }

    public function RemoveDVD($title, $category)
    {
        foreach ($this->DVDs as $key => $dvd)
        {
            if ($dvd->Title == $title && $dvd->Category == $category)
            {
                unset($this->DVDs[$key]);
                break;
            }
        }
    }

    public function editInfo($title, $category, $runningTime, $year, $price)
    {
        foreach ($this->DVDs as $dvd)
        {
            if ($dvd->Title == $title && $dvd->Category == $category)
            {
                $dvd->RunningTime = $runningTime;
                $dvd->Year = $year;
                $dvd->Price = $price;
                break;
            }
        }
    }

    public function DisplayByCat($category)
    {
        $dvdsInCategory = array();
        foreach ($this->DVDs as $dvd)
        {
            if ($dvd->Category == $category)
            {
                $dvdsInCategory[] = $dvd;
            }
        }
        return $dvdsInCategory;
    }

    public function DisplayByYear()
    {
        $sortedDVDs = $this->DVDs;
        usort($sortedDVDs, function ($a, $b) {
            return $a->Year - $b->Year;
        });
        return $sortedDVDs;
    }
}
