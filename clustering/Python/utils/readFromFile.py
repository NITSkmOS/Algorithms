import csv

def readFromFile(path):
    county_data = {}
    with open(path, newline='') as csvfile:
        reader = csv.reader(csvfile, delimiter=',', quotechar='|')
        for row in reader:
            id = row[0]
            x, y = float(row[1]), float(row[2])
            people = int(row[3])
            cancer_sil = float(row[4])
            county_data[(x,y)] = [people,cancer_sil]

    return county_data
