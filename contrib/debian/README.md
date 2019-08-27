
Debian
====================
This directory contains files used to package omnistorecoind/omnistorecoin-qt
for Debian-based Linux systems. If you compile omnistorecoind/omnistorecoin-qt yourself, there are some useful files here.

## omnistorecoin: URI support ##


omnistorecoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install omnistorecoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your omnistorecoinqt binary to `/usr/bin`
and the `../../share/pixmaps/omnistorecoin128.png` to `/usr/share/pixmaps`

omnistorecoin-qt.protocol (KDE)

