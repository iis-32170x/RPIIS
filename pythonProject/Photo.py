from typing import List

class Photo:

    def __init__(self, photo = str):
        self.photo = photo

    def show_info(self):
        print ("Фото: ",self.photo)
