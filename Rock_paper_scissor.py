import random 

define_variable = {
    "Rock" : 1,
    "Paper" : 2,
    "Scissor" :3
}
print(f"Instruction to play game choose : {define_variable}")

def player_function(player_choose):
    if(player_choose == 1):
        return "Rock"
    elif(player_choose == 2):
        return "Paper"
    else:
        return "Scissor"
    
def computer_function(computer_choose):
    if(computer_choose == "Rock"):
        return "Rock"
    elif(computer_choose == "Paper"):
        return "Paper"
    else:
        return "Scissor"

choice = ["Rock","Paper","Scissor"]
computer_choose = random.choice(choice)
computer_choice = computer_function(computer_choose)

player_choose = int(input("Enter number : "))
player_choice = player_function(player_choose)

print(f"Player choose : {player_choice} ")
print(f"Computer choose : {computer_choice}")

if (computer_choice == player_choice):
    print("Game Draw")
elif(computer_choice == "Rock" and player_choice=="Scissor"):
    print("Computer Won")

elif(computer_choice == "Scissor" and player_choice=="Paper"):
    print("Computer Won")

elif(computer_choice == "Paper" and player_choice=="Rock"):
    print("Computer Won")

else:
    print("Player Won")
