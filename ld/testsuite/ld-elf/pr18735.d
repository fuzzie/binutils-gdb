#ld: -r
#readelf: -s

Symbol table '.symtab' contains .* entries:
#...
[ 	]*[0-9]+: [0-9a-fA-F]* +1 +OBJECT +GLOBAL +DEFAULT +[0-9]+ +foo@FOO
#...
[ 	]*[0-9]+: [0-9a-fA-F]* +1 +OBJECT +GLOBAL +DEFAULT +[0-9]+ +bar@@FOO
[ 	]*[0-9]+: [0-9a-fA-F]* +1 +OBJECT +GLOBAL +DEFAULT +[0-9]+ +foo
[ 	]*[0-9]+: [0-9a-fA-F]* +1 +OBJECT +GLOBAL +DEFAULT +[0-9]+ +bar
#pass
