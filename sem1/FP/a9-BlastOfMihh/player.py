from copy import deepcopy

class Cell:
    def __init__(self):
        self._attacked=False
        self._plane_head=None
        self._occupied=False

    @property
    def occupied(self):
        return self._occupied
    @property
    def head(self):
        return self._plane_head
    @property
    def attacked(self):
        return self._attacked

    def occupy(self):
        self._occupied=True

    def set_head(self, plane):
        self._plane_head=plane
        self._occupied=True

    def attack(self):
        # print("hi")
        self._attacked=True
        if self._plane_head!=None:
            # self._plane_head.kill()
            return self._plane_head
        return None

    def __str__(self):
        if self._attacked:
            if self._occupied:
                return 'X'
            return 'o'
        if self._plane_head!=None:
            return 'H'
        if self._occupied:
            return '@'
        return '#'


class Board:
    def __init__(self, rows, cols):
        self._cells=[[Cell() for i in range(cols)] for i in range(rows)]
        self._plane_cnt=0
        for row in self._cells:
            for c in row:
                c=deepcopy(c)

    def __getitem__(self, row):
        return self._cells[row]

    def __str__(self):
        ans=""
        for cell_row in self._cells:
            for c in cell_row:
                ans+=str(c)
            ans+="\n"
        return ans

    @property
    def unpacked_str(self):
        ans=[]
        for cell_row in self._cells:
            rans=""
            for c in cell_row:
                rans+=str(c)
            ans.append(rans)
        return ans
    # def add_plane(self, direction, row, col):
    def add_plane(self, row, col):
        """      2,0
            0,0  @
               @@@@@
                 @
            3,0 @@@ 3,4
        4
        """
        if not (row>=0 and row+4<len(self._cells) and col+4<len(self._cells[0]) and col>=0):
            raise ValueError("The plane does not fit the board")
        def place_plane_down():
            plane=[]
            i=0
            for j_len in [1,5,1,3]:
                for j in range(j_len):
                    plane.append((i,j+5-j_len//2))
                i+=1
            return plane
        # def place_plane_up():
        #     plane=[]
        #     i=0
        #     for j_len in [3,1,5,1]:
        #         i+=1
        #         for j in range(j_len):
        #             plane.append((i,j+5-j_len//2))
        #     return plane
        # def place_plane_left():
        #     plane=[]
        #     i=0
        #     for j_len in [3,1,5,1]:
        #         i+=1
        #         for j in range(j_len):
        #             plane.append((j+5-j_len//2, i))
        #     return plane
        # def place_plane_right():
        #     plane=[]
        #     i=0
        #     for j_len in [1,5,1,3]:
        #         i+=1
        #         for j in range(j_len):
        #             plane.append((j+5-j_len//2, i))
        #     return plane
        # if direction=='u':
        if True:
            plane=place_plane_down()
        # elif direction=='d':
        #     plane=place_plane_down()
        # elif direction=='l':
        #     plane=place_plane_left()
        # elif direction=='r':
        #     plane=place_plane_right()


        for i,j in plane:
            if self._cells[row+i][col+7+j].occupied:
                raise ValueError("The planes are overlapping")
        self._cells[row][col+2].set_head(True)
        self._plane_cnt+=1
        for i,j in plane:
            self._cells[row+i][col+2+5-j].occupy()



class Player:
    def __init__(self, rows, cols): # planes):
        # self._cells=[[Cell()]*cols for i in range(rows)]
        self._own_board=Board(rows, cols)
        self._other_board=[[',' for i in range(cols)]for i in range(rows)]
        # for plane in planes:
        #     self._own_board
    @property
    def plane_cnt(self):
        return self._own_board._plane_cnt
    @plane_cnt.setter
    def plane_cnt(self, cnt):
        self._own_board._plane_cnt=cnt

    @property
    def board(self):
        return self._own_board

    def __str__(self):
        ans=str(self._own_board)
        i=0
        ans=""
        b_str= self._own_board.unpacked_str
        for i in range(len(self._other_board)):
            ans+=(b_str[i]+' '+str().join(self._other_board[i])+"\n")
        # for s in ans:
        #     # print(str().join(self._other_board))
        #     print(s)
            # s+=str().join(self._other_board[i])
            # i+=1
        # print(ans)
        return ans


if __name__=="__main__":
    p=Player(25,20)
    # b.add_plane(15, 10)
    print(p)
