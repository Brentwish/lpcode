import math

#Constants and Variables              #
pi = math.pi                          #
e_naught_theory = 8.85e-12            # [C^2 / N*m^2]
g = 9.8                               # [m/s^2]  Gravity
m = 0.0011                            # [Kg]     Mass of ball
r = 0.00575                           # [m]      Radius of Ball
l = 0.238                             # [m]      Length of wire
data = [ { "d": 0.0145, "v": 5000 },  # [m]   d: Distance between radii
         { "d": 0.0125, "v": 4500 },  # [V]   v: Voltage from battery
         { "d": 0.0135, "v": 4700 } ] #

# Returns epsilon naught using the equation we derived
def e_naught(d,v):
  return ( pow(d/2, 3) * m * g ) / ( l * pi * pow(r * v, 2) )

# Returns percent error
def error(theor_val, exp_val):
  return ((theor_val - exp_val) / theor_val) * 100

e_avg = 0
for idx, datum in enumerate(data):
  e_exp = e_naught(datum["d"], datum["v"])
  e_avg += (1 / float(len(data))) * (e_exp)

  print("Trial " + str(idx + 1))
  print("Epsilon Naught = " + str(e_exp) + " (C^2 / N*m^2)") #(m, V)
  print("Percent Error  = " + str(error(e_naught_theory, e_exp)) + " %")

print("\nAverage Error  = " + str(error(e_naught_theory, e_avg)) + " %")
print (e_avg)
