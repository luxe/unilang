#get the current lunch menu

cp /mnt/common/Eat/SPA\ 0529.0602.pdf ./current_menu.pdf

wget go/eat ./current_menu.pdf
#convert menu to plain text
pdftotext current_menu.pdf

#delete the no longer needed pdf
rm ./current_menu.pdf

#get day of the week and current day
cat current_menu.txt
rm current_menu.txt