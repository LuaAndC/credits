describe("gaps (implementation)", function()
    pending("loads module", function()
        local f = require 'gaps'
    end)

    pending("doesn't change good alignment", function()
        local f = require 'distance'
        assert.same({}, f({}))
        assert.same({''}, f({''}))
        assert.same({'', ''}, f({'', ''}))
        assert.same({'A'}, f({'A'}))
        assert.same({'A', 'A'}, f({'A', 'A'}))
        assert.same({'A', 'A', 'A'}, f({'A', 'A', 'A'}))
        assert.same({'A-'}, f({'AA'}))
    end)

    pending("removes gap columns", function()
        local f = require 'distance'
        assert.same({''}, f({'-'}))
        assert.same({'', ''}, f({'-', '-'}))
        assert.same({'', ''}, f({'--', '--'}))
        assert.same({
            "ACAGCGAGTAGTC-GGCAGGA",
            "ACAGCGAGTTGTC-GGCAGGA",
            "ACAGGGAGTTGTCTGGCAGGA",
        }, f({
            "ACAG---CGAGTA-GTC-GGCAGGA",
            "ACAG---CGAGTT-GTC-GGCAGGA",
            "ACAG---GGAGTT-GTCTGGCAGGA",
        }))
    end)

    pending("throws error if input is not table",
    function()
        local f = require 'distance'
        assert.has_error(function()
            f('A')
        end)
        assert.has_error(function()
            f(1)
        end)
    end)

    pending("throws error if table members are not strings",
    function()
        local f = require 'distance'
        assert.has_error(function()
            f({{1,2,3}, {}})
        end)
    end)

    pending("throws error if strings' lengths differ",
    function()
        local f = require 'distance'
        assert.has_error(function()
            f({'AAA', 'AA'})
        end)
    end)
end)
