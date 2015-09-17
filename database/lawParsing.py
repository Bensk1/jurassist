# encoding=utf8  
import sys  
from lxml import etree

reload(sys)  
sys.setdefaultencoding('utf8')

tree = etree.parse("BJNR002190897.xml")
root = tree.getroot()

for child in root:
    metadaten = child[0]
    paragraph = metadaten.find("enbez")

    if paragraph is not None:

        paragraph = paragraph.text
        if not "§" in paragraph:
            continue

        try:
            titel = metadaten.find("titel").text
        except:
            titel = "kein Titel"

        if titel and titel == "(weggefallen)":
            gesetztesText = ""
            print paragraph
            print titel
            print gesetztesText
            continue

        content = child[1][0].find("Content")

        if content is not None:

            gesetztesText = ""
            for absatz in content:
                try:
                    gesetztesText += absatz.text
                except:
                    pass

        print paragraph
        print titel
        print gesetztesText
