import sys, time

sys.path.append('..')

from Navio import ADC_lib

adc = ADC_lib.AD_converter()
results = [0]*adc.channel_count

while (True):
    s = ''
    for i in range (0, adc.channel_count):
        results[i] = adc.read(i)
        s += 'A{0}: {1:6.4f}V '.format(i, results[i]/1000)
    print s
    time.sleep(0.5)
