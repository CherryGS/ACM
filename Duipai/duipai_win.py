import filecmp
import os
import time
import json as js

# import cyaron


def loadSetting(path):
    if not os.path.isfile(path):
        with open(path, "w") as a:
            a.write(js.dumps(settings))
            print("Please fill in setting.json.")
            exit()
    with open(path, "r") as a:
        return js.loads(a.read())


def load():
    path = os.path.abspath(".")
    # path = '.'
    settings = loadSetting(path + "/setting.json")
    makeP = path + "/make/" + settings["makeName"] + ".py"
    if settings["spjName"] != 0:
        spjP = path + "/spj/" + settings["spjName"] + ".py"
        Check_Path(spjP, "SPJ FILE NEEDED.")
    Check_Path(makeP)
    return makeP


def Check_Path(path, str="No file"):
    if not os.path.isfile(path):
        with open(path, "w") as a:
            pass
        print(str)
        exit()


def compile_():
    Check_Path("./pre/wa.cpp", "YOUR CODE NEEDED.")
    Check_Path("./pre/ac.cpp", "AC CODE NEEDED.")
    os.system("g++ ./pre/wa.cpp -std=c++14 -o ./pre/wa.exe")
    os.system("g++ ./pre/ac.cpp -std=c++14 -o ./pre/ac.exe")


def compair():
    # TODO(requests): Support special judge
    return filecmp.cmp("./file/wa.out", "./file/ac.out")


# --------------------------------------------------------------#
spjP = ""
cnt = 1
settings = {"makeName": "Unknown", "timeLimit": 0, "mxTestC": 1000}

makeP = load()
compile_()

mx = settings["mxTestC"]
tim = settings["timeLimit"]

print("Test start :")

while cnt <= mx:
    os.system("python %s > ./file/tmp.in".replace("/", "\\") % makeP)

    print("-----The %d / %d group.-----" % (cnt, mx))

    Time_A = time.time()
    os.system("./pre/wa.exe < ./file/tmp.in > ./file/wa.out".replace("/", "\\"))
    Time_B = time.time()
    A = Time_B - Time_A
    print("Time for wa : %f " % A)

    os.system("./pre/ac.exe < ./file/tmp.in > ./file/ac.out".replace("/", "\\"))
    Time_C = time.time()
    B = Time_C - Time_B
    print("Time for ac : %f " % B)

    cnt = cnt + 1

    if (tim != 0) and (A > tim or (B > tim)):
        print("TLE")
        break

    if compair():
        print("AC")
    else:
        print("WA")
        break
    print("--------------------------------")

if cnt == mx + 1:
    print("You pass the test , but check out carefully !")
else:
    print("G G !")
