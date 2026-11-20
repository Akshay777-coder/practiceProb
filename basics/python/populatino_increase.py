"""
Current Population - 23056985
Increasing @ 10% each year.
Find year wise population for next 10 year
"""

current_population = 23056985
rate = 0.10

for i in range(0,10):
    inc_pop = round(current_population * rate)
    current_population += inc_pop   


print(f"Year wise population for next 10 years is: ", current_population)