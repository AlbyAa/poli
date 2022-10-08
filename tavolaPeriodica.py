
import random

elementi = {"H":"idrogeno", "He":"elio", "Li":"litio","Be":"berilio","B":"boro",
            "C":"carbonio",
            "N":"azoto",
            "O":"ossigeno",
            "F":"fluoro",
            "Ne":"neon",
            "Na":"sodio",
            "Mg":"magnesio",
            "Al":"alluminio",
            "Si":"silicio",
            "P":"fosforo",
            "S":"zolfo",
            "Cl":"cloro",
            "Ar":"argon",
            "K":"potassio",
            "Ca":"calcio",
            "Sc":"scandio",
            "Ti":"titanio",
            "V":"vanadio",
            "Cr":"cromo",
            "Mn":"manganese",
            "Fe":"ferro",
            "Co":"cobalto",
            "Ni":"nichel",
            "Cu":"rame",
            "Zn":"zinco",
            "Ga":"gallio",
            "Ge":"germanio",
            "As":"arsenico",
            "Se":"selenio",
            "Br":"bromo",
            "Kr":"kripton",
            "Rb":"rubidio",
            "Sr":"stronzio",
            "Y":"ittrio",
            "Zr":"zirconio",
            "Nb":"niobio",
            "Mo":"molibdeno",
            "Tc":"tecnezio",
            "Ru":"rutenio",
            "Rh":"rodio",
            "Pd":"palladio",
            "Ag":"argento",
            "Cd":"cadmio",
            "In":"indio",
            "Sn":"stagno",
            "Sb":"antimonio",
            "Te":"tellurio",
            "I":"iodio",
            "Xe":"xenon",
            "Cs":"cesio",
            "Ba":"bario",
            "La":"lantanio",
            "Hf":"afnio",
            "Ta":"tantalio",
            "W":"tungsteno",
            "Re":"renio",
            "Os":"osmio",
            "Ir":"iridio",
            "Pt":"platino",
            "Au":"oro",
            "Hg":"mercurio",
            "Ti":"titanio",
            "Pb":"piombo",
            "Bi":"bismuto",
            "Po":"polonio",
            "At":"astato",
            "Rn":"radon",
            "Fr":"francio",
            "Ra":"radio",
            "Ac":"attinio"
            }
elementiRand = random.sample(list(elementi),len(elementi))


def chiedi(boh):
    temp = {}
    for elemento in boh:
        print(elemento, end=" ")
        inp = input()
        if(inp != elementi[elemento]):
            print(f"SBAGLIATO: {elementi[elemento]}")
            temp[elemento] = elementi[elemento]
    return temp        
            
def main():
    
    sbagliati = {}
    for elemento in elementiRand:
        print(elemento, end=" ")
        inp = input()
        if(inp != elementi[elemento]):
            print(f"SBAGLIATO: {elementi[elemento]}")
            sbagliati[elemento] = elementi[elemento]
    
    while sbagliati is not None:
        sbagliati = chiedi(sbagliati)
    
main()