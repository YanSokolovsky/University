# standart problem of smokers
Initially, there are three avid smokers sitting around a table. Each of them has an infinite amount of one of three components available: one smoker has tobacco,
the second smoker has paper, and the third smoker has matches. All three components are needed to make and smoke cigarettes.

Also, in addition to the smokers, there is a bartender who helps them make cigarettes: he non-deterministically chooses two smokers,
takes one component each from their supply, and places it on the table. A third smoker takes the ingredients from the table and uses them to make a cigarette, which he smokes for a while.
At this time, the bartender, seeing the table empty, again selects two smokers at random and places their components on the table. The process is repeated indefinitely.

The smokers, by the condition of the problem, are honest: they do not hide the components given by the bartender - they only roll a cigarette when they finish the previous one.
If the bartender puts, for example, tobacco and paper on the table while the match supplier is smoking,
the tobacco and paper will remain untouched on the table until the match smoker finishes his cigarette and only then picks up the tobacco and paper.
