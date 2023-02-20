from DVD import DVD

class DVDController:
    def __init__(self):
        self.DVDs = []

    def RestoreCatalog(self, file_path):
        with open(file_path, 'r') as file:
            lines = file.readlines()
            for line in lines:
                fields = line.strip().split(',')
                title = fields[0].strip()
                category = fields[1].strip()
                running_time = int(fields[2].replace(' Mins.', ''))
                year = int(fields[3].strip())
                price = float(fields[4].strip())
                self.DVDs.append(DVD(title, category, running_time, year, price))

    def SaveCatalog(self, file_path):
        with open(file_path, 'w') as file:
            for dvd in self.DVDs:
                file.write(f'{dvd.Title}, {dvd.Category}, {dvd.RunningTime} Mins., {dvd.Year}, {dvd.Price}\n')

    def AddDVD(self, title, category, running_time, year, price):
        self.DVDs.append(DVD(title, category, running_time, year, price))

    def RemoveDVD(self, title, category):
        for dvd in self.DVDs:
            if dvd.Title == title and dvd.Category == category:
                self.DVDs.remove(dvd)
                break

    def editInfo(self, title, category, running_time, year, price):
        for dvd in self.DVDs:
            if dvd.Title == title and dvd.Category == category:
                dvd.RunningTime = running_time
                dvd.Year = year
                dvd.Price = price
                break

    def DisplayByCat(self, category):
        dvds_in_category = []
        for dvd in self.DVDs:
            if dvd.Category == category:
                dvds_in_category.append(dvd)
        return dvds_in_category

    def DisplayByYear(self):
        return sorted(self.DVDs, key=lambda dvd: dvd.Year)
