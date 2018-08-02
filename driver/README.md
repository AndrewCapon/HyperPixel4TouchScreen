Added firmware writing of:

```touchscreen-size-x```
	Sets the maximum x size (narrow edge)
	
```touchscreen-size-y```
	Sets the maximum Y size (long edge)
	
```touchscreen-x2y```
	If included sets x2y flag on, otherwise x2y flag is off.
	
	
E
xample with touch screen offering 16 times resolution of lcd

```
touchscreen-size-x = <7680>;
touchscreen-size-y = <12800>;
```





boot/config and hyperpixel4.dts fragments for different orientations:

```
framebuffer_width=480
framebuffer_height=800
display_rotate=0
```


    fragment@3 {
        target = <&i2c_gpio>;
        __overlay__ {
            /* needed to avoid dtc warning */
            #address-cells = <1>;
            #size-cells = <0>;
            ft6236: ft6236@5d {
                compatible = "goodix,gt911";
                reg = <0x5d>;
                interrupt-parent = <&gpio>;
                interrupts = <27 2>;
                touchscreen-inverted-x;
	    };
        };
    };


```
framebuffer_width=800
framebuffer_height=480
display_rotate=1
```

    fragment@3 {
        target = <&i2c_gpio>;
        __overlay__ {
            /* needed to avoid dtc warning */
            #address-cells = <1>;
            #size-cells = <0>;
            ft6236: ft6236@5d {
                compatible = "goodix,gt911";
                reg = <0x5d>;
                interrupt-parent = <&gpio>;
                interrupts = <27 2>;
                touchscreen-swapped-x-y;
	    };
        };
    };


```
framebuffer_width=480
framebuffer_height=800
display_rotate=2
```

    fragment@3 {
        target = <&i2c_gpio>;
        __overlay__ {
            /* needed to avoid dtc warning */
            #address-cells = <1>;
            #size-cells = <0>;
            ft6236: ft6236@5d {
                compatible = "goodix,gt911";
                reg = <0x5d>;
                interrupt-parent = <&gpio>;
                interrupts = <27 2>;
                touchscreen-inverted-y;
	    };
        };
    };


```
framebuffer_width=800
framebuffer_height=480
display_rotate=3
```

    fragment@3 {
        target = <&i2c_gpio>;
        __overlay__ {
            /* needed to avoid dtc warning */
            #address-cells = <1>;
            #size-cells = <0>;
            ft6236: ft6236@5d {
                compatible = "goodix,gt911";
                reg = <0x5d>;
                interrupt-parent = <&gpio>;
                interrupts = <27 2>;
                touchscreen-inverted-x;
                touchscreen-inverted-y;
                touchscreen-swapped-x-y;
	    };
        };
    };


