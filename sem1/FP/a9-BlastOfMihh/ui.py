import ui


class UI:
    def __init__(self, game):
        self._game=game


    def _enter_planes(self):
        for i in range(3):
            print("Enter plane "+str(i)+" coordonates:", end=" ")
            try:
                x=int(input("x:"))
                y=int(input("y:"))
                self._game.human.board.add_plane(x, y)
                print("Your board:",self._game.human.board, sep="\n")

                #TODO make it so you place the planes correctly
            except Exception as e:
                print(str(e))
                # print("Invalid plane position")
                i-=1

    def main(self):
        self._enter_planes()
        while True:
            print("Enter move:")
            try:
                x=int(input("x:"))
                y=int(input("y:"))
                move_result=self._game.make_move(x,y)
            except Exception as e:
                print(str(e))
            else:
                print(self._game.human)
                # print(self._game._bot)
                if move_result!=None:
                    print(move_result)
                if self._game.winner!="Undetermined":
                    print("And the winner is ", self._game.winner)
                    break
