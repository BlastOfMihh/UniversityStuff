
class PlayUI():
    def __init__(self, game):
        self._game=game

    def main(self):
        print("Playing")
        while True:
            print("Output", self._game)
            cmd=input("Enter move:")
            try:
                _game.add_letter(cmd)
            except Exception as e:
                print(str(e))


class UI:

    def __init__(self, play_ui, game):
        self._play_ui=play_ui
        self._game=game

    def main(self):
        while True:
            print("\nEnter command",
                  "1. Add a phrase",
                  "2. Play",
                  "0. Exit",
                  sep="\n")
            cmd=input(">")
            try :
                pass
                assert int(cmd)<=2 and int(cmd)>=0
            except:
                print("Invalid command")
            else:
                if cmd=="0":
                    exit(0)
                elif cmd=="2":
                    print("\n")
                    self._play_ui.main()
                    exit(0)
                elif cmd=="1":
                    try:
                        phrase=input(">Type the phrase>")
                        self._game.add_phrase(phrase)
                    except ValueError as ve:
                        print(str(ve))
                    else:
                        print("Phrase added :}")
