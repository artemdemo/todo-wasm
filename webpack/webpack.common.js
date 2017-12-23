const HtmlWebpackPlugin = require('html-webpack-plugin');
const DefinePlugin = require('webpack').DefinePlugin;
const IgnorePlugin = require('webpack').IgnorePlugin;
const extractStyles = require('./extractStyles');

/**
 * @param options {Object}
 * @param options.isProduction {Boolean}
 * @param options.buildFolder {String}
 * @param options.appVersion {String}
 * @param options.extractStylesFile {Boolean}
 */
module.exports = (options) => {
    return {
        entry: {
            bundle: './frontend/index.js',
        },
        output: {
            path: `${process.cwd()}/${options.buildFolder}`,
    
            // @docs https://webpack.js.org/guides/caching/#deterministic-hashes
            filename: options.isProduction ?
                './[name]-[chunkhash].js' :
                './[name].js',
            chunkFilename: options.isProduction ?
                './[id].chunk-[chunkhash].js' :
                './[id].chunk.js',
            publicPath: '/',
        },
        resolve: {
            extensions: ['.js'],
        },
        module: {
            rules: [
                {
                    test: /\.(js)?$/,
                    exclude: /node_modules/,
                    use: 'babel-loader',
                },
    
                extractStyles.moduleRule(options.extractStylesFile),
    
                {test: /\.(png|gif|jpg)(\?.*$|$)/, use: 'url-loader?limit=100000&name=images/[hash].[ext]'},
                {test: /\.(json)(\?.*$|$)/, use: 'json-loader'},
                {test: /\.(html)(\?.*$|$)/, use: 'html-loader'},
            ],
        },
        plugins: [
            // Ignoring warnings for following plugins, case they doesn't matter
            new IgnorePlugin(/regenerator|nodent|js-beautify/, /ajv/),
    
            // Defining global ENV variable
            new DefinePlugin({
                ENV: {production: options.isProduction},
            }),
    
            new HtmlWebpackPlugin({
                template: './frontend/index.ejs',
                filename: './index.html',
                appVersion: options.appVersion,
            }),
            ...extractStyles.plugins(options.extractStylesFile, options.isProduction)
        ],
    };
}