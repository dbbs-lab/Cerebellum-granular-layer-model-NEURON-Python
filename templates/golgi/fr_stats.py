# -*- coding: utf-8 -*-

import numpy as np

a = [11.472630184860302, 12.729619349050774, 12.580968734627836, 13.491180141021852, 14.477784545888566, 11.598059030741826, 13.181857601286717, 13.615978350632528, 13.50941762289651, 14.996163772095342, 11.685153840236589]

b = [12.07674220732163, 12.374535954934675, 10.867811749154191, 13.418546840226719, 10.071542682528831, 11.270876737624173, 11.515664690972416, 10.693988081405964, 12.854992303955783, 11.557058728585686, 12.885614737110524]

c = [6.6124331143875077, 5.6195560550851411, 8.01023917531694, 7.4840114301474099, 8.8866862060073029, 9.0592334495020399, 8.1958815695337641, 9.4922494088799159, 7.9017435369101907, 9.2357423228145663, 9.5675795732436306]

print np.mean(a), np.mean(b), np.mean(c)


#npf = 4257
#ngrc = 383
#nmli = 20
d = [20.019680363803733, 23.046355371475773, 21.767226719331305, 18.882716413686722, 19.877534175097502, 23.377547390420549, 20.973337644578006, 22.204762067496603, 23.040088033831388, 20.052851158618328, 19.667350502759515]

#npf = 3912
#ngrc = 173
#nmli = 20
e = [2.1777003484241333, 2.1369614189471267, 2.4918569674163011, 2.0313848966588828, 3.562839583163397, 1.6845297003642317, 2.2846698652077535, 1.5827323896337506, 0.4263710494067553, 1.3014196319145588]

print np.mean(d), np.std(d), np.mean(e), np.std(e)

#npf = 3912
#ngrc = 173
#nmli = 17
#fr_mli = 47
#f = [5.8798606127315418, 7.4952303080065796, 7.5687856399695637, 7.8377917873793272, 6.1244800571787872, 5.7376461306907265, 9.5361712272745329, 7.8897493289642666, 6.0329148738120573, 7.1334308235704134, 7.0914202257639385]


#npf = 3912
#ngrc = 173
#nmli = 16
#fr_mli = 47
f = [7.7110460735189514, 8.6607831080313229, 9.9215682920630286, 8.8590558291130463, 8.2363135633431401, 8.8579994549169694, 8.3060790115982215, 9.6841413539036356, 8.1001037826029645, 10.043672038259082, 8.5890729813759208]


npf = 3912
ngrc = 173
nmli = 9

# Firing rates (Hz)
fr_pf = .1
fr_grc = 1
fr_mli = 47

g = [7.8800181583245594, 8.2542302930482858, 8.0418174507639275, 7.5374732334251302, 7.8856917551876693, 7.2294133847619628, 7.4906367041408686, 7.0088135830978056, 7.6506437843063653, 7.3485027425843725, 6.184982518850858]

print np.mean(f),np.mean(g)


#npf = 4257
#npf = 3912
npf = 1997

#ngrc = 383
#ngrc = 173
ngrc = 1
nmli = 9

# Firing rates (Hz)
fr_pf = .1
fr_grc = 1
fr_mli = 47
#[nan, 2.7425437093051328, nan, nan, nan, 0.35113592471730953, nan, nan, nan, nan, nan]

npf = 4257
#npf = 3912
#npf = 1997

ngrc = 383
#ngrc = 173
#ngrc = 1
nmli = 9

# Firing rates (Hz)
fr_pf = .1
fr_grc = 1
fr_mli = 47


h = [13.98362892227563, 15.668508851899695, 13.18723267660817, 12.206182770668837, 13.523679116942436, 14.331780723795411, 14.091162950589748, 14.288630332760803, 14.527719407514288, 13.436576773707223, 13.57738686221944]

print np.mean(h)