arp -a -i en0 | cut -d '(' -f 2 | rev | cut -d ')' -f 2 | rev
