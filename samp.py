import sys

# Parse the variables
variables = []
for line in sys.stdin:
    if line.startswith('V'):
        variables.append(line.split()[1])
    else:
        break

# Parse the inequalities
inequalities = []
for line in sys.stdin:
    if line.startswith('R'):
        inequalities.append(list(map(int, line.split()[1:])))

def fourier_motzkin(inequalities):
    while len(inequalities[0]) > 3:
        new_inequalities = []
        for i in range(len(inequalities)):
            for j in range(i+1, len(inequalities)):
                a, b = inequalities[i], inequalities[j]
                if a[-3] < 0 < b[-3] or a[-3] > 0 > b[-3]:
                    new_a = [a[i]*b[-3] - b[i]*a[-3] for i in range(len(a)-2)] + [a[-2], a[-1]*b[-3] - b[-1]*a[-3]]
                    new_inequalities.append(new_a)
        inequalities = new_inequalities

    return inequalities

result = fourier_motzkin(inequalities)
for r in result:
    if r[0] > 0 and r[-1] < 0 or r[0] < 0 and r[-1] > 0:
        print('Impossible')
        break
else:
    print('Solution exists')
