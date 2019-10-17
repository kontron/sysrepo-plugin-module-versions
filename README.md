Provides data about installed yang modules.

Currently, always constant values are delivered.
(Those, which are delivered from a TTTech's DE-IP 1.6.0)

Request data from netopeer2-cli:
> get --filter-xpath /module-versions:module-versions//*
> get --filter-xpath /module-versions:module-versions/module[name='ieee802-dot1q-bridge']/*
> get --filter-subtree		# In vi, enter "<module-versions/>" (without the quotes)


Request data from netopeer-cli:
netconf> get --filter		# In vi, enter "<module-versions/>" (without the quotes)
