change = -1
while(change < 0):
    try:
        change = float(input("O hai! How much change is owed? "))
    except ValueError:
        continue
    
amount_coin = 0
rest = (round(change*100))

while not(rest == 0): 
    if (rest >= 25):
        rest -= 25
        amount_coin+=1
    elif (rest >= 10):
        rest -= 10
        amount_coin+=1
    elif (rest >= 5):
        rest -= 5
        amount_coin+=1
    elif (rest >= 1):
        rest -= 1
        amount_coin+=1

print(amount_coin);