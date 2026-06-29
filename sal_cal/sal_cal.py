total_salary = 13690
sal_per_day = total_salary / 30
night_award = 1000
attendance_bonus = 1000
otph = sal_per_day / 4

working_days = int(input("Enter your Working days: "))
sal_cal = sal_per_day * working_days

ot = float(input("Enter your overtime hour count: "))

sal_cal += otph * ot

leave_count = int(input("Enter leave count: "))

night_leave = ""

while True:
    if leave_count == 0:
        break
    night_leave = input("Took a leave at night shift? \'yes\' or \'no\': ").lower()
    if night_leave not in ('yes', 'no'):
        print("Enter \'yes\' or \'no\'")
        continue
    break

if leave_count == 0:
    sal_cal += night_award + attendance_bonus
if not leave_count == 0:
    if night_leave == 'yes':
        sal_cal += 0
    if night_leave == 'no':
        sal_cal += attendance_bonus

diploma_deduction = 325
sal_cal -= diploma_deduction
print(f"\nWorking days : {working_days}")
print(f"Overtime : {ot}")
print(f"Leave count: {leave_count}")
print(f"Leave deduction : {round(leave_count * sal_per_day)}")
print(f"Diploma deduction {diploma_deduction}")
print(f"Salary : {round(sal_per_day * working_days,2)}")
print(f"Total Salary: {round(sal_cal,2)}")
