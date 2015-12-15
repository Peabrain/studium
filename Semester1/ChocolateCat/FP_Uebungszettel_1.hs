--Fabien Geeraert und Ailis Oßwald
{-1.Aufgabe
	div 1 2 -> 0,weil div immer ganzzahlig teilt
	8^0 -> 1,weil x^0=1
	rem 5 2 -> 1,weil quot 5 2 auf 4 abrundet richtung 0 und der Rest 1 ist
	sqrt 3 -> gibt die Wurzel von 3 aus
	"ba"<"aba" -> False, weil nur der erste Wert des Strings verglichen wird und b in der ascii-Tabelle einen höheren Wert hat
	8^200 -> gibt die ganzzahlige 200.Potenz von 8 an
	4/=5 -> True, weil 4 ungleich 5 ist
	--mod 5 2 -> 1, weil div 5 2 immer abrundet, hier auf 4 Rest:1
	sqrt(-1) -> NaN, weil keine Wurzeln aus negativen Zahlen gebildet werden können
	True < False -> False, weil True auch als 1 bezeichnet wird und False als 0
	2**1023 -> gibt die 1023.Potenz von 2 an, allerdings nicht als ganze Zahl
	0.1==0.3/3 -> False, weil haskell Dezimalzahlen als Binärcode darstellt und daher nicht richtig teilt(eigtl 0.3/3=0.1)
	rem 5 (-2) -> 1 weil quot 5 (-2) auf 4 abrundet Rest:1
	exp 1-> gibt den Exponentialwert von 1 aus
	True||False -> True, weil bei oder min. 1 Wert true sein muss
	2**1024 -> gibt die 1024.Potenz von 2 an, haskell gibt Infinity aus, weil die Zahl zu groß ist
	abs -7 -> gibt eigtl immer den Betrag an, da hier die Klammern fehlen gibt es eine Fehlermeldung, da - ein Operator ist
	mod 5 (-2) -> -1, weil div auf 6 aufrundet Rest -1
	'z'<'A' -> False, weil die kleinen Buchstaben in der ascii-Tabelle vor den großen stehen und daher einen größeren Wert haben
	True&&False -> False, weil und immer nur True ist wenn beide Werte True sind
-}
	
{-2.Aufgabe
	(-) ((+) ((+) 1 2) 3) (-2) -> 8, weil hoskell von innen nach außen rechnet
		also 1+2=3 , danach 3+3=6 und 6-(-2)=8; Datentyp Num, weil haskell die Argumente als ganze Zahlen einordnet
	2**3 + (2^3) -> 16.0, weil auf beiden Seiten des + die 3.Potenz von zwei(8) ist
		Datentyp:Float, weil ** mit Float rechnet, nicht mit ganzzahlige Zahlen
	log 1 -> 0.0, weil der logarithmus von 1 0 ist
		Datentyp: Floating, weil der logarithmus einer Zahl eine Dezimalzahl sein kann
	div 1 2.0 -> 0.0, weil hier ganzzahlig geteilt und abgerundet wird
		Datentyp: Fractional, weil der Eingabewert 2.0 als Fractional eingeordnet wird und 1 auch als Fractional ausgelsen werden kann
	mod 4 (-3) -> -2, weil div immer einen negativen Rest hat, wenn das zweite Argumrnt negativ ist
		Datentyp: Integral, da div immer ganzzahlig teil, haskell aber nicht weiß wie groß die zahlen sind verwendet es Integer, statt int
	(4 `mod` 5) == (4 `rem` 5) -> True, weil div und quot im positiven Bereich immer das gleich Ergebnis haben
		Datentyp: Bool, weil bei == immer ein Wahrheitswert ausgegeben wird, da überprüft wird ob das was links vom operator steht identisch ist mit dem was rechts steht
	(-4 `mod` 5) == (-4 `rem` 5) -> False, weil mod und rem mit negativen Zahlen verschieden rechnen
		Datentyp: Bool, weil überprüft wird ob a==b, also a gleich b ist
	(4 `mod` (-5)) == (4 `rem` (-5)) -> False, weil mod und rem mit negativen Zahlen verschieden rechnen
		Datentyp: Bool, weil überprüft wird ob a==b, also a gleich b ist
	succ 4 * 8.0 -> 40.0, weil haskell mit dem ersten Operator beginnt, hier succ 4 und den Nachfolger der 4 , also 5 mit 8 multipliziert
		Datentyp: Fractional, weil Fractional ein Num ist und 4 daher zu Fractional werden kann ist der Ausgabetyp Fractional
	succ (4 * 8) ->33, weil 4*8 in Klammern ist, wird dies zuerst ausgeführt und dann wird der nachfolger der 32 ausgegegben
		Datentyp: Num, weil haskell die Argument als Ziffern definiert, aber nicht als ganzzahlige oder dezimal
	if (mod 1 2)==0 then "ja" else "nein" -> "nein", weil mod 1 2 /= 0 ist
		Datentyp: [Char], also ein String weil "" für einen String stehen
	True || undefined -> True, weil bei einem Oder nur ein Argument True sein muss und das erste Argument dies erfüllt gibt haskell sofort True aus
		 Datentyp: Bool, weil zwei Wahrheitswerte verglichen werden um daraus einen Wahrheitswert zu schlussfolgern
	True && not (True || undefined) -> False, weil True oder undefined True ist, dies aber negiert wird und True && False -> False, weil bei && beide Argumente True sein müssen
		Datentyp: Bool, da Wahrheitswerte verglichen werden
	True && (undefined || True) -> undefined, weil die Kalmmer zuerst gelöst wird, da das erste Argument undefined ist gibt haskell die Fehlermeldung raus, dass es mit undefined || nicht lösen kann
		Datentyp: die Funktion an sich wird als Bool definiert, undefined hat keinen Datentypen,weil es nicht definiert ist
	3/0 ** 2 -> Infinity, weil 3/0 Infinity ist, da 3/0=3.3333(periode) ist und jede Potenz von Infinity Infinity ist
		Datentyp: Fractional, weil ** keine ganzzahlige Potenz ist, der Datentyp von Infiity ist Fractional
	2 - 0/0 -> NaN, weil 0/0 nicht möglich ist und daher NaN
		Datentyp: Fractional, weil bei dem / Operator auch Dezimalzahlen als Ergebnid möglich sind, der Datentyp von NaN ist Floating
-}
	
--3.Aufgabe
--Signatur, definieren der Datentypen für alle Variablen, Double für das Startkapital, weil auch Cent-Beträge möglich sind,
	--Jahreszins, wir als Dezimalzahl eingegebn für 3 Prozent 0,03, die Laufzeit könnte zB 1 1/2 Jahre, also 1,5 sein
--als Eingabewert werden das Startkapital, der Jahreszins und die Laufzeit benötigt
--diese Werte werden dann in die vorgegebene Formel zur Berechnung des Endkapitals eingesetzt
	endkapitalRechner :: Double -> Double -> Double -> Double
	endkapitalRechner startK jZins laufZ = (startK*((exp 1)**(jZins*laufZ)))
	
--4.Aufgabe
--weil 1 rad ca.57.295779513082 grad sind
	rad2grad :: Double -> Double
	rad2grad rad = rad*57.295779513082
	
--weil 1 grad ca.0.017453292519943 rad sind	
	grad2rad :: Double -> Double
	grad2rad grad = grad*0.017453292519943
	
--Double weil Gradzahlen nur ungenau als ganze Zahlen dargestellt werden können	
	gkEntfernung :: Double -> Double -> Double -> Double -> Double
	--da haskell mit bogenmaß arbeitet muss man die Eingabewerte bevor sie verrechnet werden in rad umwandeln und das Ergebnis wieder ins Gradmaß
	gkEntfernung bg1 lg1 bg2 lg2 = rad2grad(111.2225685* acos(sin(grad2rad bg1)*sin(grad2rad bg2) + cos(grad2rad bg1)*cos(grad2rad bg2)*cos((grad2rad lg1)-(grad2rad lg2))))

--5.Aufgabe
--Signatur der Funktion, als Eingabe wird ein beliebiges Zeichen benötigt, Ausgabe Wahrheitswert
	istKlammer :: Char -> Bool
	--für jede Klammer ein Guard, in dem überprüft wird ob das eingegebene Zeichen übereinstimmt, also eine Klammer ist
	--durch otherwise werden alle anderen Zeichen als False ausgegeben
	istKlammer argument
					| argument=='('	= True
					| argument==')'	= True
					| argument=='['	= True
					| argument==']'	= True
					| argument=='{'	= True
					| argument=='}'	= True
					| otherwise 	= False
					
--6.Aufgabe
--Signatur, als Eingabe drei Doubles und der höchste Wert soll ausgegeben werden
	max3 :: (Double,Double,Double) -> Double
	max3 	(a,b,c)
		--überprüfen ob a größer als b und c ist oder falls c oder b genauso groß sind wie a, ausgegeben wird a 
				| a>=b && a>=c = a
		--überprüfen ob b größer als c ist oder gleichgroß, weil b auf jeden Fall größer ist als a ausgegebn wird dann b	
				| b>=c         = b
		--da c nicht kleiner oder gleich a und b ist, muss c größer sein
				| otherwise    = c
				
--Signatur, es werden drei Zahlen für rot grün blau eingegeben, die anfangs ganzzahlig sind durch das Teilen aber zu Dezimalzahlen werden können
	rgb2cmyk :: (Double,Double,Double) -> (Double,Double,Double,Double)
	--es wird überprüft ob sich die Werte nicht zwischen 0 und 255 befinden
	rgb2cmyk	(r,g,b) = if r>255 || r<0 || g>255 || g<0 || b>255 || b<0
		--falls dies zutrifft wird eine Fehlermeldung ausgegeben 
						then error "keine Farbwerte! Die Werte müssen sich zwischen 0 und 255 befinden."
			--sind die Werte zwischen 0 und 255, wird hier überprüft ob die Werte alle 0 sind 
						else if r==0 && g==0 && b==0
							then (0,0,0,1)
					--sind die Werte größer 0 wird hier dann mit der vorgegebenen Formel umgerechnet
					--let in für w, mit der Funktion max3 nimmt w den Wert des höchsten Ergebnisses an
							else let w=max3(r/255,g/255,b/255)		
								in (((w-(r/255))/w),((w-(g/255))/w),((w-(b/255))/w),(1-w))
			