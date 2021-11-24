echo "Copying to /usr/lib/cgi-bin..."
sudo cp read_button.cgi /usr/lib/cgi-bin/
echo "Done"
echo
echo "Adjusting permissions..."
sudo chmod +s /usr/lib/cgi-bin/read_button.cgi
echo "Done"
echo
