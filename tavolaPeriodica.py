
import random

'''
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

'''
# elementi = {v: k for k, v in elementi.items()}

'''
elementi = { # VALENZE
    "H":"1",
    "Li":"1",
    "Na":"1",
    "K":"1",
    "Cs":"1",
    "Ag":"1",
    "Mg":"2",
    "Ca":"2",
    "Sr":"2",
    "Ba":"2",
    "Zn":"2",
    "Cd":"2",
    "Al":"3",
    "H":"-1",
    "F":"-1",
    "Cl":"-1",
    "Br":"-1",
    "I":"-1",
    "O":"-2",
    "S":"-2",
    "N":"-3",
    
    "Cr":"2,3",
    "Cb":"2,3",
    "Fe":"2,3",
    "Hg":"1,2",
    "Pb":"2,4",
    "Cu":"1,2",
    "Sn":"2,4"
}
'''

elementi = {
    "NH4 +":"ammonio",
    "H3O +":"idronio",
    "CH3COO -":"acetato",
    "CN -":"cianuro",
    "OH -":"idrossido",
    "ClO -":"ipoclorito",
    "ClO2 -":"clorito",
    "ClO3 -":"clorato",
    "ClO4 -":"perclorato",
    "NO2 -":"nitrito",
    "NO3 -":"nitrato",
    "MnO4 -":"permanganato",
    "CO3 2-":"carbonato",
    "HCO3 -":"idrogenocarbonato",
    "CrO4 2-":"cromato",
    "Cr2O7 2-":"dicromato",
    "O2 2-":"perossido",
    "PO4 3-":"fosfato",
    "HPO4 2-":"idrogenofosfato",
    "H2PO4 -":"diidrogenofosfato",
    # "SO3 2-":"solfito",
    # "SO4 2-":"solfato",
    # "HSO4 -":"idrogenosolfato"
}

elementi = {v: k for k, v in elementi.items()}

elementiRand = random.sample(list(elementi),len(elementi))

def chiedi(boh):
    temp = {}
    for elemento in boh:
        print(elemento, end=" ")
        inp = input()
        if(inp.lower() != elementi[elemento].lower()):
            print(f"SBAGLIATO: {elementi[elemento]}")
            temp[elemento] = elementi[elemento]
    return temp        
            
def main():
    
    sbagliati = {}
    for elemento in elementiRand:
        print(elemento, end=" ")
        inp = input()
        if(inp.lower() != str(elementi[elemento]).lower()):
            print(f"SBAGLIATO: {elementi[elemento]}")
            sbagliati[elemento] = elementi[elemento]
    
    while len(sbagliati) != 0:
        sbagliati = chiedi(sbagliati)
    
main()