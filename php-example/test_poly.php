<?php
include "./Zh2pyPoly.php";
$z2p = new Zh2pyPoly("../dict/polymorphic.dict","../dict/gbk.dict");
print_r($z2p->getPinyin("���Ƕ����й���.����һƥ������.����Ϣ����.һҳ������."));
