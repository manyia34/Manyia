import random 
class computer_player():
    choice = ["Rock","Paper","Scissor"]

    def __init__(self,name):
        self.name = name
        print(f"Welcome : {self.name}\n")

    def instruction(self): 
        self.define_variable = {
        "Rock" : 1,
        "Paper" : 2,
        "Scissor" :3
        }

        print("Instruction of Game:")
        for key, value in self.define_variable.items():
            print(f"{value}. {key}")
    
    def player_function(self,player_choose):
        self.player_choose = player_choose
        if(self.player_choose == 1):
            return "Rock"
        elif(self.player_choose == 2):
            return "Paper"
        else:
            return "Scissor"
    
    def computer_function(self,computer_choose):
        self.computer_choose = computer_choose
        if(self.computer_choose == "Rock"):
            return "Rock"
        elif(self.computer_choose == "Paper"):
            return "Paper"
        else:
            return "Scissor"
    
    def logic(self,computer_choice,player_choice,name):
        self.name = name
        self.computer_choice = computer_choice  
        self.player_choice = player_choice     
        if (self.computer_choice == self.player_choice):
            return "Game Draw"
        
        elif(self.computer_choice == "Rock" and self.player_choice=="Scissor"):
            return "Computer Won"
    
        elif(self.computer_choice == "Scissor" and self.player_choice=="Paper"):
            return "Computer Won"
    
        elif(self.computer_choice == "Paper" and self.player_choice=="Rock"):
            return "Computer Won"
    
        else:
            return (f"{self.name} Won")

class player_player():
        def __init__(self,player1,player2):
            self.player1 = player1
            self.player2 = player2
        
        def instruction(self): 
            self.define_variable = {
                "Rock" : 1,
                "Paper" : 2,
                "Scissor" :3
        }
            print("Instruction of Game:")
            for key, value in self.define_variable.items():
                print(f"{value}. {key}")
        
        def player1_function(self,player1_guess):
            self.playerguess = player1_guess
            if(self.playerguess == 1):
                return "Rock"
            elif(self.playerguess == 2):
                return "Paper"
            else:
                return "Scissor"
        
        def player2_function(self,player2_guess):
            self.playerguess = player2_guess
            if(self.playerguess == 1):
                return "Rock"
            elif(self.playerguess == 2):
                return "Paper"
            else:
                return "Scissor"
        
        def logic(self,player1_move,player2_move):
            self.player1 = player1_move
            self.player2 = player2_move
            if(self.player1 == self.player2):
                return {f"Draw"}
            elif(self.player1 =="Rock" and self.player2 =="Scissor"):
                return {f"Player1 Won!"}
            
            elif(self.player1 =="Scissor" and self.player2=="Paper"):
                return {f"Player1 Won!"}
                
            elif(self.player1 =="Paper" and self.player2=="Rock"):
                return {f"Player1 Won!"}
                
            else:
                return {f"Player2 Won!"}


# Menu of game modes
print("<----- Welcome in Rock Paper and Scissor game ----->\n")
print("<----Choose Mode---->")
print("1. Player vs Player")
print("2. Player vs Computer")
print("3. Exit")
mode = int(input("Enter mode you want to play : "))

match mode :
    case 1:
        print("Ok ! You choose player vs player\n")
        player1 = input("Player 1 Name :")
        player2 = input("Player 2 Name :")

        player = player_player(player1,player2)

        player1_guess = int(input("Player 1 Move : "))
        player1_move = player.player1_function(player1_guess)

        player2_guess = int(input("Player 2 Move : "))
        player2_move = player.player2_function(player2_guess)

        print(f"Player1 choose : {player1_move}")
        print(f"player2 choose : {player2_move}\n")
        result = player.logic(player1_move,player2_move)
        print(f"Winner of Game : {result}")

        print("Thank You for Playing !")
        exit()

    case 2:
        print("Ok ! You choose player vs computer\n")
        
        name = input("Enter player name : ")
        player = computer_player(name)

        player.instruction()


        computer_choose = random.choice(computer_player.choice)
        computer_choice = player.computer_function(computer_choose)

        player_choose = int(input("Choose your move : "))
        player_choice = player.player_function(player_choose)

        print(f"\nPlayer choose : {player_choice}")
        print(f"Computer choose : {computer_choice}\n")

        result = player.logic(computer_choice,player_choice,name)
        print(f"Winner of Game : {result}")

        print("Thank You for Playing !")
        exit()

    case 3:
        print("Thank You !")
        exit()



