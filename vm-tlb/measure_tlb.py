import subprocess
import matplotlib.pyplot as plt

NUMPAGES_EXP = [0, 1, 2, 3, 3.5, 3.75, 4, 5, 6, 7, 8, 9, 10, 11]
NUMTRIALS = 100

def main():
    x = []
    y = []

    for exp in NUMPAGES_EXP:
        NUMPAGES = int(2 ** exp)
        p = subprocess.run(["./tlb", str(NUMPAGES), str(NUMTRIALS)], capture_output=True)
        out_lines = p.stdout.decode('utf-8').split('\n')
        print(out_lines[-2])
        x.append(NUMPAGES)
        y.append(float(out_lines[-2]))

    plt.plot(x, y, marker='x', markersize=12)
    plt.xlabel('Number of pages')
    plt.ylabel('Time per access (ns)')
    plt.grid()
    plt.show()




if __name__ == '__main__':
    main()
