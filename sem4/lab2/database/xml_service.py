from xml.dom.minidom import Document
import xml.etree.ElementTree as ET

from utils import logger

from models import Sportsman
from .repositories import SportsmanRepository

class XMLService:
    def __init__(self, root_name: str, item_name: str):
        self.doc = Document()

        self.root = self.doc.createElement(root_name)
        self.doc.appendChild(self.root)
    
        self.item_name = item_name

    def dicts_to_xml(self, data: list[dict[str, str]]) -> str:
        for item in data:
            item_element = self.doc.createElement(self.item_name)

            for key, value in item.items():
                elem = self.doc.createElement(key)
                text = self.doc.createTextNode(str(value))
                elem.appendChild(text)
                item_element.appendChild(elem)
            
            self.root.appendChild(item_element)  
        
        xml_str = self.doc.toprettyxml(indent="  ")
        return xml_str

    def xml_to_dicts(self, xml_str: str) -> list[dict[str, str]]:
        if not xml_str:
            logger.error("Empty xml string")
            return []
        try:
            root = ET.fromstring(xml_str)
        except Exception as e:
            logger.error(f"Error while parsing xml: {e}")
            return []

        data = []
        for item in root:
            item_data = {}
            for elem in item:
                item_data[elem.tag] = elem.text
            data.append(item_data)
        
        return data
    


# if __name__ == "__main__":
#     controller = SportsmanRepository()
#     sportsmen = list(map(Sportsman.model_dump, controller.get_all()))
#     service = XMLService("sportsmen", "sportsman")

#     # xml_str = service.convert_dicts_to_xml(sportsmen)
#     # print(xml_str)
#     with open("123", "r") as f:
#         xml_str = f.read()
#         data = service.xml_to_dicts(xml_str)
#         print(data)
