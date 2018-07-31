<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.0.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="psiboard">
<packages>
<package name="USB-C">
<pad name="B12" x="7.675" y="2.35" drill="0.28" diameter="0.6" rot="R180"/>
<pad name="B11" x="7.275" y="3.05" drill="0.28" diameter="0.6" rot="R180"/>
<pad name="B10" x="6.475" y="3.05" drill="0.28" diameter="0.6" rot="R180"/>
<pad name="B9" x="6.075" y="2.35" drill="0.28" diameter="0.6" rot="R180"/>
<pad name="B7" x="5.275" y="2.35" drill="0.28" diameter="0.6" rot="R180"/>
<pad name="B6" x="4.475" y="2.35" drill="0.28" diameter="0.6" rot="R180"/>
<pad name="B5" x="4.075" y="3.05" drill="0.28" diameter="0.6" rot="R180"/>
<pad name="B4" x="3.675" y="2.35" drill="0.28" diameter="0.6" rot="R180"/>
<pad name="B3" x="3.275" y="3.05" drill="0.28" diameter="0.6" rot="R180"/>
<pad name="B2" x="2.475" y="3.05" drill="0.28" diameter="0.6" rot="R180"/>
<pad name="B1" x="2.075" y="2.35" drill="0.28" diameter="0.6" rot="R180"/>
<pad name="DC@1" x="0.745" y="2.95" drill="0.8" diameter="1" shape="long" rot="R90"/>
<pad name="DC$4" x="0.385" y="7.34" drill="0.8" diameter="1" shape="long" rot="R90"/>
<pad name="DC@3" x="9.365" y="7.34" drill="0.8" diameter="1" shape="long" rot="R90"/>
<hole x="1.2" y="1.7" drill="0.6"/>
<hole x="8.55" y="1.7" drill="0.6"/>
<pad name="DC@2" x="9.005" y="2.95" drill="0.8" diameter="1" shape="long" rot="R90"/>
<pad name="B8" x="5.675" y="3.05" drill="0.28" diameter="0.6" rot="R180"/>
<wire x1="0" y1="0" x2="9.75" y2="0" width="0.127" layer="21"/>
<wire x1="9.75" y1="0" x2="9.75" y2="9.87" width="0.127" layer="21"/>
<wire x1="9.75" y1="9.87" x2="0" y2="9.87" width="0.127" layer="21"/>
<wire x1="0" y1="9.87" x2="0" y2="0" width="0.127" layer="21"/>
<smd name="A12" x="2.125" y="1.4" dx="0.6" dy="0.2" layer="1" rot="R90"/>
<smd name="A11" x="2.625" y="1.4" dx="0.6" dy="0.2" layer="1" rot="R90"/>
<smd name="A10" x="3.125" y="1.4" dx="0.6" dy="0.2" layer="1" rot="R90"/>
<smd name="A9" x="3.625" y="1.4" dx="0.6" dy="0.2" layer="1" rot="R90"/>
<smd name="A8" x="4.125" y="1.4" dx="0.6" dy="0.2" layer="1" rot="R90"/>
<smd name="A7" x="4.625" y="1.4" dx="0.6" dy="0.2" layer="1" rot="R90"/>
<smd name="A6" x="5.125" y="1.4" dx="0.6" dy="0.2" layer="1" rot="R90"/>
<smd name="A5" x="5.625" y="1.4" dx="0.6" dy="0.2" layer="1" rot="R90"/>
<smd name="A4" x="6.125" y="1.4" dx="0.6" dy="0.2" layer="1" rot="R90"/>
<smd name="A3" x="6.625" y="1.4" dx="0.6" dy="0.2" layer="1" rot="R90"/>
<smd name="A2" x="7.125" y="1.4" dx="0.6" dy="0.2" layer="1" rot="R90"/>
<smd name="A1" x="7.625" y="1.4" dx="0.6" dy="0.2" layer="1" rot="R90"/>
<text x="-1.25" y="10" size="0.8128" layer="25" rot="R270">&gt;NAME</text>
</package>
</packages>
<symbols>
<symbol name="USB-C">
<wire x1="0" y1="0" x2="63.5" y2="0" width="0.254" layer="94"/>
<wire x1="63.5" y1="0" x2="63.5" y2="30.48" width="0.254" layer="94"/>
<wire x1="63.5" y1="30.48" x2="0" y2="30.48" width="0.254" layer="94"/>
<wire x1="0" y1="30.48" x2="0" y2="0" width="0.254" layer="94"/>
<pin name="A12" x="5.08" y="-2.54" length="short" rot="R90"/>
<pin name="A11" x="10.16" y="-2.54" length="short" rot="R90"/>
<pin name="A10" x="15.24" y="-2.54" length="short" rot="R90"/>
<pin name="A9" x="20.32" y="-2.54" length="short" rot="R90"/>
<pin name="A8" x="25.4" y="-2.54" length="short" rot="R90"/>
<pin name="A7" x="30.48" y="-2.54" length="short" rot="R90"/>
<pin name="A6" x="35.56" y="-2.54" length="short" rot="R90"/>
<pin name="A5" x="40.64" y="-2.54" length="short" rot="R90"/>
<pin name="A4" x="45.72" y="-2.54" length="short" rot="R90"/>
<pin name="A3" x="50.8" y="-2.54" length="short" rot="R90"/>
<pin name="A2" x="55.88" y="-2.54" length="short" rot="R90"/>
<pin name="A1" x="60.96" y="-2.54" length="short" rot="R90"/>
<pin name="B12" x="58.42" y="-5.08" length="middle" rot="R90"/>
<pin name="B11" x="53.34" y="-5.08" length="middle" rot="R90"/>
<pin name="B10" x="48.26" y="-5.08" length="middle" rot="R90"/>
<pin name="B9" x="43.18" y="-5.08" length="middle" rot="R90"/>
<pin name="B8" x="38.1" y="-5.08" length="middle" rot="R90"/>
<pin name="B7" x="33.02" y="-5.08" length="middle" rot="R90"/>
<pin name="B6" x="27.94" y="-5.08" length="middle" rot="R90"/>
<pin name="B5" x="22.86" y="-5.08" length="middle" rot="R90"/>
<pin name="B4" x="17.78" y="-5.08" length="middle" rot="R90"/>
<pin name="B3" x="12.7" y="-5.08" length="middle" rot="R90"/>
<pin name="B2" x="7.62" y="-5.08" length="middle" rot="R90"/>
<pin name="B1" x="2.54" y="-5.08" length="middle" rot="R90"/>
<text x="0" y="33.02" size="1.27" layer="94">&gt;NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="USB-C">
<gates>
<gate name="G$1" symbol="USB-C" x="0" y="5.08"/>
</gates>
<devices>
<device name="" package="USB-C">
<connects>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A10" pad="A10"/>
<connect gate="G$1" pin="A11" pad="A11"/>
<connect gate="G$1" pin="A12" pad="A12"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="A6" pad="A6"/>
<connect gate="G$1" pin="A7" pad="A7"/>
<connect gate="G$1" pin="A8" pad="A8"/>
<connect gate="G$1" pin="A9" pad="A9"/>
<connect gate="G$1" pin="B1" pad="B1"/>
<connect gate="G$1" pin="B10" pad="B10"/>
<connect gate="G$1" pin="B11" pad="B11"/>
<connect gate="G$1" pin="B12" pad="B12"/>
<connect gate="G$1" pin="B2" pad="B2"/>
<connect gate="G$1" pin="B3" pad="B3"/>
<connect gate="G$1" pin="B4" pad="B4"/>
<connect gate="G$1" pin="B5" pad="B5"/>
<connect gate="G$1" pin="B6" pad="B6"/>
<connect gate="G$1" pin="B7" pad="B7"/>
<connect gate="G$1" pin="B8" pad="B8"/>
<connect gate="G$1" pin="B9" pad="B9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="pinhead" urn="urn:adsk.eagle:library:325">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1X02" urn="urn:adsk.eagle:footprint:22309/1" library_version="3">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-1.905" y1="1.27" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<pad name="1" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-2.6162" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.54" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
</package>
<package name="1X02/90" urn="urn:adsk.eagle:footprint:22310/1" library_version="3">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-2.54" y1="-1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="6.985" x2="-1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="0" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="6.985" x2="1.27" y2="1.27" width="0.762" layer="21"/>
<pad name="1" x="-1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<text x="-3.175" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="4.445" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-1.651" y1="0.635" x2="-0.889" y2="1.143" layer="21"/>
<rectangle x1="0.889" y1="0.635" x2="1.651" y2="1.143" layer="21"/>
<rectangle x1="-1.651" y1="-2.921" x2="-0.889" y2="-1.905" layer="21"/>
<rectangle x1="0.889" y1="-2.921" x2="1.651" y2="-1.905" layer="21"/>
</package>
</packages>
<packages3d>
<package3d name="1X02" urn="urn:adsk.eagle:package:22435/2" type="model" library_version="3">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X02"/>
</packageinstances>
</package3d>
<package3d name="1X02/90" urn="urn:adsk.eagle:package:22437/2" type="model" library_version="3">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X02/90"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="PINHD2" urn="urn:adsk.eagle:symbol:22308/1" library_version="3">
<wire x1="-6.35" y1="-2.54" x2="1.27" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="1.27" y2="5.08" width="0.4064" layer="94"/>
<wire x1="1.27" y1="5.08" x2="-6.35" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="5.08" x2="-6.35" y2="-2.54" width="0.4064" layer="94"/>
<text x="-6.35" y="5.715" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-1X2" urn="urn:adsk.eagle:component:22516/3" prefix="JP" uservalue="yes" library_version="3">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="PINHD2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X02">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22435/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="/90" package="1X02/90">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22437/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="USB-C" library="psiboard" deviceset="USB-C" device=""/>
<part name="JP1" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X2" device="" package3d_urn="urn:adsk.eagle:package:22435/2"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="USB-C" gate="G$1" x="43.18" y="45.72"/>
<instance part="JP1" gate="G$1" x="12.7" y="68.58"/>
</instances>
<busses>
</busses>
<nets>
<net name="VBUS" class="0">
<segment>
<pinref part="USB-C" gate="G$1" pin="B4"/>
<wire x1="60.96" y1="40.64" x2="60.96" y2="35.56" width="0.1524" layer="91"/>
<label x="60.96" y="35.56" size="1.4224" layer="95" rot="R270"/>
</segment>
<segment>
<pinref part="USB-C" gate="G$1" pin="A9"/>
<wire x1="63.5" y1="43.18" x2="63.5" y2="35.56" width="0.1524" layer="91"/>
<label x="63.5" y="35.56" size="1.4224" layer="95" rot="R270"/>
</segment>
<segment>
<pinref part="JP1" gate="G$1" pin="1"/>
<wire x1="10.16" y1="71.12" x2="2.54" y2="71.12" width="0.1524" layer="91"/>
<label x="2.54" y="71.12" size="1.4224" layer="95" rot="R180"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="USB-C" gate="G$1" pin="B1"/>
<wire x1="45.72" y1="40.64" x2="45.72" y2="35.56" width="0.1524" layer="91"/>
<label x="45.72" y="35.56" size="1.4224" layer="95" rot="R270"/>
</segment>
<segment>
<pinref part="USB-C" gate="G$1" pin="A12"/>
<wire x1="48.26" y1="43.18" x2="48.26" y2="35.56" width="0.1524" layer="91"/>
<label x="48.26" y="35.56" size="1.4224" layer="95" rot="R270"/>
</segment>
<segment>
<pinref part="JP1" gate="G$1" pin="2"/>
<wire x1="10.16" y1="68.58" x2="2.54" y2="68.58" width="0.1524" layer="91"/>
<label x="2.54" y="68.58" size="1.4224" layer="95" rot="R180"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
