# explosive-c4
# Copyright (C) 2014-2022 Salvo "LtWorf" Tomaselli
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
# author Salvo "LtWorf" Tomaselli <tiposchi@tiscali.it>

.PHONY: dist
dist:
	rm -rf /tmp/explosive-c4/
	rm -rf /tmp/explosive-c4-*
	mkdir /tmp/explosive-c4/
	cp -R * /tmp/explosive-c4/
	( \
		cd /tmp; \
		tar --exclude '*.user' -zcf explosive-c4.tar.gz \
			explosive-c4/src \
			explosive-c4/LICENSE \
			explosive-c4/README.md \
			explosive-c4/CHANGELOG \
			explosive-c4/CODE_OF_CONDUCT.md \
	)
	mv /tmp/explosive-c4.tar.gz ./explosive-c4_`head -1 CHANGELOG`.orig.tar.gz
	gpg --sign --armor --detach-sign ./explosive-c4_`head -1 CHANGELOG`.orig.tar.gz

.PHONY: deb-pkg
deb-pkg: dist
	$(RM) -r /tmp/explosive-c4*
	mv explosive-c4*orig* /tmp
	cd /tmp; tar -xf explosive-c4*orig*.gz
	cp -r debian /tmp/explosive-c4/
	cd /tmp/explosive-c4; dpkg-buildpackage --changes-option=-S
	mkdir -p deb-pkg
	mv /tmp/explosive-c4*.* deb-pkg
	lintian --pedantic -E --color auto -i -I deb-pkg/*changes deb-pkg/*deb
