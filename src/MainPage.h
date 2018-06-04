/**
 *
 *Voor dit project hebben wij gemaakt van het drie lagen model. De drie gebruikte lagen zijn Front Layer, Logic Layer en de IO layer.
 *Elke laag neemt een andere taak op zich in de code. De front layer bevat de Commando buffer en execution. Deze worden ingevoerd door de gebruiker en omgezet naar bruikbaare functioncalls voor de Logic layer.
 *De logic layer zet alle vormen, BMP's en texten die binnengekomen zijn van de front layer om naar pixel posities op het scherm. Deze pixels worden dan door de IO layer op het scherm gezet.
 *
 *De 3 lagen zijn onafhankelijk van elkaar aan te passen zolang de functioncalls voor functies die communiceren met een andere laag gelijk blijven. Dit zorgt er voor dat het heel gemakklijk is om een aanpassing te maken aan het scherm omdat dan alleen de IO layer maar herschreven hoeft te worden en de rest van de code dan gewoon blijft werken.
 *In de afbeelding is te zien welke functionaliteit in welke laag aanwezig is.
 *
 */

