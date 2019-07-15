1-)La valeur final dans la memoire partager est de 300; 
2-)Sur des taches plus complexe, on aurait pu rencontrer un probleme d'acces concurrent, les processus pourrait ecraser les valeurs modifier par les autres, mais dans notre cas ici, la tache etant simple, aucun probleme ne s'est poser, le resultat attendu etait bien 300. Neamoins utiliser un sleep ou un verrou serait plus prudent pour s'assurer qu'un processus ne gene pas les autres.
3-)Implementation de la solution des verrou(voir code)
