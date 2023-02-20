<?php

class DVD
{
    public $Title;
    public $Category;
    public $RunningTime;
    public $Year;
    public $Price;

    public function __construct($title, $category, $runningTime, $year, $price)
    {
        $this->Title = $title;
        $this->Category = $category;
        $this->RunningTime = $runningTime;
        $this->Year = $year;
        $this->Price = $price;
    }
}