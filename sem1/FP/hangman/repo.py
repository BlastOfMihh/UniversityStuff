from copy import deepcopy

# find add
class Repo():

    def __init__(self):
        self._data=[]

    def add(self, new):
        self._data.append(new)

    def find(self, item):
        for elem in self._data:
            if item==elem:
                return True
        return False

    def get_all(self):
        return deepcopy(self._data)


class FileRepo(Repo):
    def _update_data(self):
        old_data=self._file.read()
        tkns=old_data.split("\n")
        for t in tkns:
            if t!="":
                self._data.append(t)

    def __init__(self):
        super().__init__()
        self._file_name="sentences.txt"
        self._file=open(self._file_name, "r+")
        self._update_data()

    def add(self, new):
        super().add(new)
        self._file.write(new)
