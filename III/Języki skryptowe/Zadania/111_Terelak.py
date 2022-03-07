import datetime

date = datetime.datetime.strptime('Dec 31 2021  11:59PM', '%b %d %Y %I:%M%p')

print("Data:", date.date())
print("Czas:", date.time())
print("Date-time:", date)