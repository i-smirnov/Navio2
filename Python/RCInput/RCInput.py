import sys, time

sys.path.append('..')

from Navio import RCInput_lib

rcin = RCInput_lib.RCin()

while (True):
    period = rcin.read(2)
    print period
    time.sleep(1)
