Youtube:
-------
* **Used CDN (content delivery network, Akami) to handle load.**

**Thumbnails:**
Serving thumnails was tough. Ran into filesystem per directory limit on number of files. 
Under high load apache performed badly.

**Solutions:**
Used squid (reverse proxy) initially. Worked well for a while. 
Finally they setteled on Google's bigtable, a distribued datastore. Lower latency because it uses a multilevel cache.

**Database:**
Used MySQL in the beginning. Went from single `server` `->` `master with slaves` `->` `partitioned the database`, then settled on sharding approach.

* Priorotize the traffic. Video was there main focus. So it was given highest priority. Social stuff was redirected to less capable servers.
